package com.test.dao;
import com.test.entity.Student;
import java.io.IOException;
import java.util.List;
import org.apache.ibatis.session.SqlSession;

public interface StudentDao {
    List<Student> show() throws IOException;
}
