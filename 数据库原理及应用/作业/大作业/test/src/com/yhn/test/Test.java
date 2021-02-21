package com.yhn.test;

import com.yhn.pojo.People;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class Test {
    public static void main(String[] args) throws IOException {
//        读取 mybatis配置文件
        InputStream is = Resources.getResourceAsStream("mybatis.xml");
//         创建session工厂
        SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
//          用session工厂打开session
        SqlSession session = factory.openSession();

        List<People> list = session.selectList("com.yhn.mapper.PeopleMapper.selAll");


        for (People people : list){
            System.out.println(people.toString());
        }


        session.close();
    }
}