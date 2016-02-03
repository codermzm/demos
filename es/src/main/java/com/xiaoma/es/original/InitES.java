package com.xiaoma.es.original;

import io.searchbox.client.JestClient;
import io.searchbox.client.JestClientFactory;
import io.searchbox.client.config.ClientConfig;
import io.searchbox.client.config.ClientConstants;

import java.util.LinkedHashSet;

/**
 * 创建es索引
 */
public class InitES {

    /**
     * 静态,单例...
     */
    private static JestClient jestClient;

    /**
     * 获取一个jest的对象
     */
    public static JestClient jestClient() {
        if (jestClient == null) {
            JestClientFactory factory = new JestClientFactory();
            factory.setClientConfig(clientConfig());
            jestClient = factory.getObject();
        }

        return jestClient;
    }

    /**
     * 配置jest客户端,到时使用spring时,可以用配置方式 ,现在暂时使用new ...
     * @return ClientConfig
     */
    private static ClientConfig clientConfig() {
        // es的服务端地址,暂时我是用我虚拟机的(ubuntu)做服务器
        String connectionUrl = "http://120.25.216.23:9200";// 一般都是9200端口
        ClientConfig clientConfig = new ClientConfig();
        // 当你用集群时,就有可能会有多个es的服务端,这里我暂时没有集群
        LinkedHashSet servers = new LinkedHashSet();
        servers.add(connectionUrl);
        clientConfig.getServerProperties().put(ClientConstants.SERVER_LIST, servers);
        clientConfig.getClientFeatures().put(ClientConstants.IS_MULTI_THREADED, false);

        return clientConfig;
    }

}