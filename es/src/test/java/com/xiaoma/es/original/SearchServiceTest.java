package com.xiaoma.es.original;

import com.xiaoma.es.original.entity.NewsEntity;
import io.searchbox.core.Index;
import org.junit.Ignore;
import org.junit.Test;

import java.util.List;

/**
 * SearchService测试类
 */
public class SearchServiceTest {

    private SearchService searchService = new SearchService();

    /**
     * 创建news索引
     */
    @Ignore
    @Test
    public void buildSearchIndexTest() {
        searchService.builderSearchIndex();
    }

    /**
     * 创建假数据
     * */
    @Test
    public void buildDataTest() throws Exception {
        for (long i = 0; i < 1000; i++) {
            NewsEntity news = new NewsEntity();
            news.setId(i + 1);
            news.setTitle("elasticsearch RESTful搜索引擎-(java jest 使用[入门])" + (i + 1));
            news.setContent("好吧下面我介绍下jest(第三方工具),个人认为还是非常不错的...想对ES用来更好,多多研究源代码吧...迟点,会写一些关于ES的源代码研究文章,现在暂时还是入门的阶段.哈..(不敢,不敢)"
                    + (i + 1));

            searchService.save(news);
        }
    }

    /**
     * 搜索新闻
     */
    @Test
    public void searchNews() {
        String param = "个人";
        List<NewsEntity> news = searchService.searchsNews(param);
        for (int i = 0; i < news.size(); i++) {
            NewsEntity article = news.get(i);
            System.out.println(article.getId() + "   " + article.getTitle() + "   " + article.getContent());
        }
    }

}
