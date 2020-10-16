package com.lln.util;

import com.google.gson.GsonBuilder;

import java.util.HashMap;

/**
 * @author LiLinnan
 * @version 1.0
 * @date 2020/1/3 8:53
 */

public class CommonUtils {
    /**
     * 生成一条返回给前端的带有状态json信息
     *
     * @param status  状态码，本项目中 -1代表非法 0代表合理的失败 1代表成功
     * @param message 信息
     * @return 要返回给前端的json数据
     */
    public static String message(int status, String message) {
        return "{\"status\":" + status + ",\"message\":\"" + message + "\"}";
    }

    /**
     * 将没有状态的对象加上状态并转换位json并返回
     *
     * @param status 状态码，本项目中 -1代表非法 0代表合理的失败 1代表成功
     * @param object 对象
     * @return 要返回给前端的json数据
     */
    public static String mapMessage(int status, Object object) {
        HashMap<String, Object> map = new HashMap<>(2);
        map.put("status", status);
        map.put("data", object);
        return new GsonBuilder().disableHtmlEscaping().create().toJson(map);
    }
}
