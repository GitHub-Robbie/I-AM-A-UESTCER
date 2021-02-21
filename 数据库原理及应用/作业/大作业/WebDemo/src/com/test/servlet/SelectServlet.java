package com.test.servlet;
import com.test.entity.Student;
import com.test.dao.*;
import com.test.util.GetSqlSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.ibatis.session.SqlSession;


public class SelectServlet extends HttpServlet {
    private StudentDao studentDao = new StudentDaoImplement();
    protected void service(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException {
        List<Student> list = studentDao.show();
        req.setAttribute("list", list);
        req.getRequestDispatcher("index.jsp").forward(req, resp);
    }
}
