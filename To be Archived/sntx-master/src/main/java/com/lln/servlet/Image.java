package com.lln.servlet;

import com.lln.service.UserImageService;
import com.lln.util.CommonUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * @author LiLinnan
 * @version 1.0
 * @date 2020/1/3 8:31
 */

@WebServlet("/image")
public class Image extends HttpServlet {

    private UserImageService userImageService;

    @Override
    public void init() throws ServletException {
        super.init();
        userImageService = new UserImageService();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        String uid = request.getParameter("uid");
        String type = request.getParameter("type");
        if (uid == null || uid.length() == 0) {
            writer.println(CommonUtils.message(-1, "无id"));
            return;
        }
        if (type == null) {
            type = "cn";
        }
        try {
            ArrayList<String> images = "cn".equals(type) ? userImageService.getUserImage(uid) : userImageService.getUserImageTw(uid);
            if (images.size() == 0) {
                writer.println(CommonUtils.message(0, "未获取到头像"));
                return;
            }
            writer.println(CommonUtils.mapMessage(1, images));
        } catch (Exception e) {
            writer.println(CommonUtils.message(-1, "服务出现异常"));
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        doPost(request, response);
    }
}
