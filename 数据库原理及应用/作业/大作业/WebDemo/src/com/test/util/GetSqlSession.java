package com.test.util;
import java.io.IOException;
import java.io.InputStream;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

public class GetSqlSession {
    public static SqlSession createSqlSession() {
        SqlSessionFactory sqlSessionFactory = null;
        InputStream input = null;
        SqlSession session = null;
        try {
            input = Resources.getResourceAsStream("SqlMapConfig.xml");
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(input);
            session = sqlSessionFactory.openSession();
            return session;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}