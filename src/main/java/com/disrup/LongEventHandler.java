package com.disrup;

import com.lmax.disruptor.EventHandler;

public class LongEventHandler implements EventHandler<LongEvent> {

    private static Long num = new Long(0L);

    public void onEvent(LongEvent event, long l, boolean b) throws Exception {
        System.out.println("Event: " + num++);
    }

}
