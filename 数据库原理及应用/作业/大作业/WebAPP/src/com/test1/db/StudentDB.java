package com.test1.db;

import com.test1.entity.Student;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 *  操作数据库的类
 */
public class StudentDB {
    /**
     *  函数功能：获取数据库连接对象
     * @return 返回数据库连接对象
     *  使用说明：提前知道获取数据库连接对象时所需要的四大参数
     *  1、驱动类的名称（数据库不同，驱动类的名称不同）
     *  2、数据库的URL
     *  3、使用数据库时的用户名
     *  4、用户名对应的密码
     *  一定要导入相对应的jar包
     */
    private static Connection getConn(){
        //第一步：加载驱动类(如果有异常，则抛出异常或者使用try..catch..语句块处理)
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.out.println("驱动类加载失败。");
            /**
             *  这里可能报错：ClassNotFoundException
             *  错误原因：可能是驱动类的名称拼写错误，也可能是所需要的jar包没有导入
             */
        }
        //第二步：获取连接对象
        String url = "jdbc:postgresql://localhost:5432/GradeDB";
        String  username = "postgres";
        String  password = "37642749YHNcx";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url,username,password);
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("连接对象获取失败。");
        }
        //返回一个连接对象
        return conn;
    }

    /**
     *  函数功能：通过查询语句来获取数据库中的表格信息
     * @param sql
     * @return 返回一个List对象
     * @throws SQLException
     */
    public List<Student> getStudent(String sql) throws SQLException {
        //查询语句的执行结果为一个表格，即多个学生对象的集合，所有可以创建数组列表对象来存储
        List<Student> lst = new ArrayList<Student>();
        //获取连接对象
        Connection conn = getConn();
        try {
            //连接对象conn调用createStatement()方法，创建一个执行SQL语句的对象st
            Statement st = conn.createStatement();
            //执行SQL语句的对象st调用executeQuery()方法，执行查询语句，将查询到的结果返回到一个结果集中
            ResultSet rs = st.executeQuery(sql);
            //遍历结果集对象
            while(rs.next()){
                Student stu = new Student();
                stu.setsid(rs.getString("sid"));
                stu.setsname(rs.getString("sname"));
                stu.setsex(rs.getString("sex"));
                stu.setcid(rs.getString("cid"));
                stu.setcname(rs.getString("cname"));
                stu.setteacher(rs.getString("teacher"));
                stu.setscore(rs.getString("score"));
                stu.setnote(rs.getString("note"));

                lst.add(stu);
            }
        }catch (Exception e){
            System.out.println(e.getMessage());
        }finally {
            //资源使用完之后，如果没有关闭，则需要关闭
            if (conn!=null){
                conn.close();
            }
        }
        return lst;
    }

    /**
     *  函数功能：对表中数据进行增删改操作
     * @param sql
     * @return true或者false
     * @throws SQLException
     */
    public boolean studentUpdate(String sql) throws SQLException {
        //获取数据库连接对象
        Connection conn = getConn();
        try {
            //连接对象调用createStatement()方法，创建一个执行SQL语句的对象
            Statement st = conn.createStatement();
            //执行SQL语句的对象st，调用executeUpdate()方法执行SQL语句，执行结果为int类型，表示受到影响的记录条数
            //executeUpdate( )方法可以执行增删改DML语句和创建表、删除表等DDL语句
            int cnt = st.executeUpdate(sql);
            return cnt>0; //如果有记录受到影响，则表示更新操作成功
        }catch (Exception e){
            System.out.println(e.getMessage());
            return false;
        }finally {
            if (conn!=null)
                conn.close();
        }
    }

    //测试一下
    public static void main(String[] args) throws SQLException {
        List<Student> lst = new ArrayList<Student>();
        lst=(new StudentDB()).getStudent("select * from gradeview");
        for (Student stu: lst) {
            //调用Student实体类中的toString()方法，将Student对象转换成字符串输出
            System.out.println(stu.toString());
        }
//        boolean tf =(new StudentDb()).studentUpdate("update student set sage=24 where sid = 10002");
//        lst=(new StudentDb()).getStudent("select * from student");
//        for (Student stu: lst) {
//            //调用Student实体类中的toString()方法，将Student对象转换成字符串输出
//            System.out.println(stu.toString());
//        }
    }
}