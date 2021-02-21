package com.test.mybatis_test;

import com.test.entity.Student;
import com.test.dao.StudentDao;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;
public class Test {
    public static void main(String[] args) throws IOException {
        InputStream is = Resources.getResourceAsStream("SqlMapConfig.xml");
        SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
        SqlSession session = factory.openSession();
        List<Student> list = session.selectList("com.test.entity.StudentMapper.getScoreByID");
//        System.out.println(list);
        for (Student student : list){
            System.out.println(student.toString());
        }
        session.close();

    }
}

