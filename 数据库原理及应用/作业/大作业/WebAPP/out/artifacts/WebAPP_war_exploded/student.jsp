<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.test1.db.StudentDB" %>
<%@ page import="java.util.List" %>
<%@ page import="com.test1.entity.Student" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>学生成绩查询系统</title>
    <style>
        #footer {
            height: 40px;
            line-height: 40px;
            position: fixed;
            bottom: 0;
            width: 100%;
            text-align: center;
            background: #333;
            color: #fff;
            font-family: Arial;
            font-size: 12px;
            letter-spacing: 1px;
        }
    </style>
</head>

<div align="center">
    <h1>学生成绩查询系统</h1>
</div>

<div align="center">
    <div style="display: inline-block;margin-right: 20px">
        <form action="student.jsp">
        <input id="sid" name="sid" placeholder="按学号查询" style="width: 120px">
        <input type="submit" value="查询" style="color: white;background-color: black">
        </form>
    </div>

    <div style="display: inline-block;margin-right: 20px;margin-left: 20px">
        <form action="student.jsp">
            <input id="sname" name="sname" placeholder="按姓名查询" style="width: 80px">
            <input type="submit" value="查询" style="color: white;background-color: black">
        </form>
    </div>

    <div style="display: inline-block;margin-right: 20px;margin-left: 20px">
        <form action="student.jsp">
            <input id="cid" name="cid" placeholder="按课程号查询" style="width: 100px">
        <input type="submit" value="查询" style="color: white;background-color: black">
        </form>
    </div>

    <div style="display: inline-block;margin-left: 20px">
        <form action="student.jsp">
            <input id="cname" name="cname" placeholder="按课程名查询" style="width: 130px">
            <input type="submit" value="查询" style="color: white;background-color: black">
        </form>
    </div>
</div>

<div align="center">
<table border="1" cellspacing="0">
    <tr>
        <td bgcolor="#d3d3d3" align="center" style="width: 145px;height: auto">学号</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 50px;height: auto">姓名</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 50px;height: auto">性别</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 95px;height: auto">课程号</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 170px;height: auto">课程名</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 70px;height: auto">任课教师</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 50px;height: auto">成绩</td>
        <td bgcolor="#d3d3d3" align="center" style="width: 80px;height: auto">备注</td>
    </tr>

    <%
        StudentDB sdb = new StudentDB();
        String sname = request.getParameter("sname");
        String sid = request.getParameter("sid");
        String cname = request.getParameter("cname");
        String cid = request.getParameter("cid");
        String sql = null;
        if (sid != null) {
            sql = "select * from gradeview where sid like '%" + sid + "%' order by cid,sid";
        }
        else if(sname != null) {
            sql = "select * from gradeview where sname like '%" + sname + "%' order by cid,sid";
        }
        else if (cid != null) {
            sql = "select * from gradeview where cid like '%" + cid + "%' order by sid,cid";
        }
        else if (cname != null) {
            sql = "select * from gradeview where cname like '%" + cname + "%' order by sid,cid";
        }
        else {
            sql = "select * from gradeview order by cid, sid";
        }

        List<Student> lst = sdb.getStudent(sql);
        request.setAttribute("stuLst", lst);
    %>
    <c:forEach items="${stuLst}" var="stu">
        <tr id="${stu.sid}">
            <td align="center">${stu.sid}</td>
            <td align="center">${stu.sname}</td>
            <td align="center">${stu.sex}</td>
            <td align="center">${stu.cid}</td>
            <td align="center">${stu.cname}</td>
            <td align="center">${stu.teacher}</td>
            <td align="center">${stu.score}</td>
            <td align="center" style="color: red">${stu.note}</td>
        </tr>
    </c:forEach>
</table>
</div>
<div align="center">
    <a href="student.jsp">主查询页面</a>
</div>

<div id="footer">CopyRight © 2020 汤泡饭</div>
</body>
</html>