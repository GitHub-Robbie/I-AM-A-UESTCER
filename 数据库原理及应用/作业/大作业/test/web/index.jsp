<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: tommy
  Date: 2020/5/24
  Time: 17:34
  To change this template use File | Settings | File Templates.
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>$Title$</title>
</head>
<body>
<table border="1">
  <tr>
    <th>学号</th>
    <th>课程号</th>
    <th>成绩</th>
    <th>备注</th>
  </tr>
  <c:forEach items="${list}" var="people">
    <tr>
      <td>${people.sid}</td>
      <td>${people.cid}</td>
      <td>${people.score}</td>
      <td>${people.note}</td>
    </tr>
  </c:forEach>
</table>

</body>
