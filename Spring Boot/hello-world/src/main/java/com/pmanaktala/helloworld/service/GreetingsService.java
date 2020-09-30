package com.pmanaktala.helloworld.service;

import com.pmanaktala.helloworld.dto.ResponseDTO;

public interface GreetingsService {

	ResponseDTO greetUser(String username);
}
