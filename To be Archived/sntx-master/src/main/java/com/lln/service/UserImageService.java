package com.lln.service;

import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;

/**
 * @author LiLinnan
 * @version 1.0
 * @date 2020/1/3 8:34
 */

public class UserImageService {

    public ArrayList<String> getUserImage(String uid) throws Exception {
        ArrayList<String> stringArrayList = new ArrayList<>();
        for (int i = 1; ; i++) {
            String url = s(i, uid);
            URL u = new URL(url);
            HttpURLConnection connection = (HttpURLConnection) u.openConnection();
            if (connection.getResponseCode() != 200) {
                break;
            }
            stringArrayList.add(url);
        }
        return stringArrayList;
    }

    public ArrayList<String> getUserImageTw(String uid) throws Exception {
        ArrayList<String> stringArrayList = new ArrayList<>();
        for (int i = 1; ; i++) {
            String url = sTw(i, uid);
            URL u = new URL(url);
            HttpURLConnection connection = (HttpURLConnection) u.openConnection();
            if (connection.getResponseCode() != 200) {
                break;
            }
            stringArrayList.add(url);
        }
        return stringArrayList;
    }

    private String s(int num, String uid) {
        String i = (num < 10 ? "0" : "") + num;
        i = uid + i;
        return "http://nn4cn-sh-server-cbt.papegames.com/obt/" + uid + "/photo/" + i + ".png";
    }

    private String sTw(int num, String uid) {
        String i = (num < 10 ? "0" : "") + num;
        i = uid + i;
        return "http://nn4-tw.papegames.com/tw/" + uid + "/photo/" + i + ".png";
    }
}