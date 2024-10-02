#!/usr/bin/python3
"""a recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords (case-insensitive,
delimited by spaces.
Javascript should count as javascript, but java should not)."""
import requests


def count_words(subreddit, word_list):
    """Results are based on the number of times a keyword appears"""
    def fetch_data(subreddit, word_list, after='', counts={}):
        """fetch data from the api"""
        if not counts:
            counts = {word.lower(): 0 for word in word_list}
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'
        headers = {"User-Agent": 'Mozilla/5.0'}
        params = {'limit': 100, 'after': after}
        try:
            res = requests.get(
                url,
                headers=headers,
                params=params,
                allow_redirects=False)
            if res.status_code != 200:
                return
            data = res.json().get('data')
            if not data:
                return
            for post in data.get('children', []):
                title = post['data']['title'].lower().split()
                for word in word_list:
                    counts[word.lower()] += title.count(word.lower())
            after = data.get('after')
            if after:
                return fetch_data(subreddit, word_list, after, counts)
            else:
                sorted_counts = [(word, counts[word])
                                 for word in counts if counts[word] > 0]
                sorted_counts.sort(key=lambda x: (-x[1], x[0]))
                for word, count in sorted_counts:
                    print(f'{word}: {count}')
        except BaseException:
            return
    fetch_data(subreddit, word_list)
