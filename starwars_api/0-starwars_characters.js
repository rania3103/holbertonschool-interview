#!/usr/bin/node
const request = require("request");
const movie_id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movie_id}`;

request(url, async (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const chars = await JSON.parse(body).characters;
    for (const char_url of chars) {
      await new Promise((resolve, reject) => {
        request(char_url, async (error, response, body) => {
          if (!error && response.statusCode === 200) {
            console.log(JSON.parse(body).name);
          }
          resolve();
        });
      });
    }
  }
});
