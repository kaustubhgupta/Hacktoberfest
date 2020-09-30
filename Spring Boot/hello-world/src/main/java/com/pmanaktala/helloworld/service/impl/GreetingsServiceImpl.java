package com.pmanaktala.helloworld.service.impl;

import org.springframework.stereotype.Service;

import com.pmanaktala.helloworld.dto.ResponseDTO;
import com.pmanaktala.helloworld.service.GreetingsService;

@Service
public class GreetingsServiceImpl implements GreetingsService{

	@Override
	public ResponseDTO greetUser(String username) {
		ResponseDTO response = new ResponseDTO();
		
		response.setUsername(username);
		response.setMessage("Hello! Welcome to the first Spring Boot App. Happy Learning!");
		
		return response;
	}

}
