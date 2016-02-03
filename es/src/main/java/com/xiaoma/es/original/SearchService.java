package com.xiaoma.es.original;

import com.xiaoma.es.original.entity.NewsEntity;
import io.searchbox.client.JestClient;
import io.searchbox.client.JestResult;
import io.searchbox.core.Bulk;
import io.searchbox.core.Index;
import io.searchbox.core.Search;
import io.searchbox.indices.CreateIndex;
import io.searchbox.indices.DeleteIndex;
import org.elasticsearch.index.query.QueryBuilder;
import org.elasticsearch.index.query.QueryBuilders;

import java.io.IOException;
import java.util.List;

/**
 * 搜索服务
 */
public class SearchService {

    private static JestClient jestClient = InitES.jestClient();

    /**
     * 创建es news索引
     */
    public boolean builderSearchIndex() {
        int num = 10000;
        long start = System.currentTimeMillis();
        try {
            // 如果索引存在,删除索引
            DeleteIndex deleteIndex = new DeleteIndex("news");
            jestClient.execute(deleteIndex);

            // 创建索引
            CreateIndex createIndex = new CreateIndex("news");
            JestResult result = jestClient.execute(createIndex);

            return result.isSucceeded();
          /*  // Bulk 两个参数1:索引名称2:类型名称(用文章(article)做类型名称)
            Bulk bulk = new Bulk("news", "article");
            // 添加添加100万条假数据去服务端(ES)
            for (long i = 0; i < num; i++) {
                NewsEntity news = new NewsEntity();
                news.setId(i + 1);
                news.setTitle("elasticsearch RESTful搜索引擎-(java jest 使用[入门])" + (i + 1));
                news.setContent("好吧下面我介绍下jest(第三方工具),个人认为还是非常不错的...想对ES用来更好,多多研究源代码吧...迟点,会写一些关于ES的源代码研究文章,现在暂时还是入门的阶段.哈..(不敢,不敢)"
                        + (i + 1));
                bulk.addIndex(new Index.Builder(news).build());
            }
            jestClient.execute(bulk);*/
        } catch (Exception e) {
            e.printStackTrace();
        }
        long end = System.currentTimeMillis();
        System.out.println("创建索引时间:数据量是  " + num + "记录,共用时间 -->> " + (end - start) + " 毫秒");

        return false;
    }

    public boolean save(NewsEntity news) throws Exception {
        if(news == null){
            return false;
        }

        Bulk bulk = new Bulk("news", "article");
        bulk.addIndex(new Index.Builder(news).build());
        JestResult result = jestClient.execute(bulk);

        return result.isSucceeded();
    }


    /**
     * 搜索新闻
     *
     * @param param
     * @return
     */
    public List searchsNews(String param) {
        try {
            long start = System.currentTimeMillis();
            QueryBuilder queryBuilder = QueryBuilders.queryString(param);
            Search search = new Search(Search.createQueryWithBuilder(queryBuilder.toString()));
            search.addIndex("news");
            search.addType("article");
            JestResult result = jestClient.execute(search);
            long end = System.currentTimeMillis();
            System.out.println("在100万条记录中,搜索新闻,共用时间 -->> " + (end - start) + " 毫秒");

            return result.getSourceAsObjectList(NewsEntity.class);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

}
