package com.servlet;
import com.dao.impl.StudentDaoImpl;
import com.pojo.Student;
import com.dao.StudentDao;
import org.apache.ibatis.session.SqlSession;
import com.test.util.GetSqlSession;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/show")
public class ShowServlet extends HttpServlet{
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        StudentDao studentDao = new StudentDaoImpl();
        SqlSession session = GetSqlSession.createSqlSession();
        String cid = req.getParameter("cid");
        List<Student> list = studentDao.selectAll(cid,session);
        req.setAttribute("list", list);
        req.getRequestDispatcher("/index.jsp").forward(req, resp);
    }
}

