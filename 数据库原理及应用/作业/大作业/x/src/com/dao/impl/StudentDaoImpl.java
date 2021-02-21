package com.dao.impl;

import com.dao.StudentDao;
import com.pojo.Student;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class StudentDaoImpl implements StudentDao{
    @Override
    public List<Student> selectAll(String cid, SqlSession session) throws IOException{
        InputStream is = Resources.getResourceAsStream("mybatis.xml");
        /*
            前面是工厂模式，实例化工厂对象时使用构建者模式
            构建者模式的作用:简化对象的实例化过程，快速构建对象
         */
        List<Student> list = session.selectList("com.mapper.PeopleMapper.selectAll", cid);
        session.close();
        return list;
    }
}
