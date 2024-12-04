#!/usr/bin/env python3
import requests
import sys
import os
import dotenv

if __name__ == "__main__":
  args = sys.argv 
  if len(args) != 2:
    print("usage: ./get_input.py <dayNumber>")
    exit(1)

  dotenv.load_dotenv()
  SESSION_COOKIE = os.getenv("AOC_SESSION_COOKIE")
  day = int(args[1])
  url = f"https://adventofcode.com/2024/day/{day}/input"
  headers = {
    "Cookie": f"session={SESSION_COOKIE}"
  }
      
  response = requests.get(url, headers=headers)

  if response.status_code == 200:
    with open("puzzle_input.txt", "w") as file:
      file.write(response.text)
    print("puzzle input retrieved")
    exit(0)
  else:
    print(url, response)
    print(response.text)
    exit(1)