package com.pmanaktala.helloworld.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import com.pmanaktala.helloworld.dto.ResponseDTO;
import com.pmanaktala.helloworld.service.GreetingsService;

@RestController
public class GreetingsController {

	private GreetingsService greetingsService;

	@Autowired
	public GreetingsController(GreetingsService greetingsService) {
		super();
		this.greetingsService = greetingsService;
	}

	@GetMapping(value = "/greet/{username}", produces = MediaType.APPLICATION_JSON_VALUE)
	public ResponseEntity<ResponseDTO> greetUser(@PathVariable(value = "username") String username) {

		ResponseDTO greetings = greetingsService.greetUser(username);

		return new ResponseEntity<ResponseDTO>(greetings, HttpStatus.OK);

	}
}
