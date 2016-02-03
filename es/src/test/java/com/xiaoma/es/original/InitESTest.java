package com.xiaoma.es.original;

import io.searchbox.client.JestClient;
import org.junit.Assert;
import org.junit.Test;

/**
 * 创建es索引
 */
public class InitESTest {

    @Test
    public void jestClientTest(){
        JestClient jestClient = InitES.jestClient();

        Assert.assertTrue(jestClient != null);
    }

}
