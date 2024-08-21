#!/usr/bin/node
const request = require("request");
const movie_id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movie_id}`;

request(url, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const chars = JSON.parse(body).characters;
    chars.forEach((char_url) => {
      request(char_url, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          console.log(JSON.parse(body).name);
        }
      });
    });
  }
});
