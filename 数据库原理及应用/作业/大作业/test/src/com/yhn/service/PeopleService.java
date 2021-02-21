package com.yhn.service;

import com.yhn.pojo.People;
import java.io.IOException;
import java.util.List;

public interface PeopleService {

    List<People> show() throws IOException;
}
