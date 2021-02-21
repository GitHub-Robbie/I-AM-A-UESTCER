package com.yhn.service.impl;

import com.yhn.pojo.People;
import com.yhn.service.PeopleService;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class PeopleServiceImpl implements PeopleService {
    @Override
    public List<People> show() throws IOException {
        InputStream is = Resources.getResourceAsStream("mybatis.xml");
        //前面是工厂       实例化工厂对象时使用的是  构建者设计模式   名称标志:后面有Builder
        //构建者设计模式意义: 简化对象实例化过程
        SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
        SqlSession session = factory.openSession();
        List<People> list = session.selectList("com.yhn.mapper.PeopleMapper.selAll");
        session.close();
        return list;
    }
}
