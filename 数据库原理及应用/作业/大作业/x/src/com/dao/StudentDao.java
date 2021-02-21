package com.dao;

import com.pojo.Student;

import java.io.IOException;
import java.util.List;
import org.apache.ibatis.session.SqlSession;

/**
 * @Auther:yhn
 * @Date: 2020/5/24 21:33
 * @Description:
 */
public interface StudentDao {
    List<Student> selectAll(String cid, SqlSession session) throws IOException;
}
