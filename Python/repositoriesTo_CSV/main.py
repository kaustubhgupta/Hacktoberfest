import csv
from github import Github

# Set your limit of results in data.csv file
limit = 100

# Set your keyword here
keyword = "hacktoberfest"

# Below is the Access_token, if this dosent work go to "Github Settings / Developer settings"
# and generate a new Personal access token and tick the public_repo under repo and click Generate token
# and replace the token below to new one
ACCESS_TOKEN = '4960164dcbe9319e95290b83c33f5c34e52ddfa9'


def search_github(keyword):
    # Formatting search query
    # the query format is "<search_keyword_1>+ ... +<search_keyword_n>+<qualifier_1>+ ... +<qualifier_n>"
    query = keyword + '+in:readme+in:description'

    # Sorting repository by stars and in decreasing order
    result = g.search_repositories(query, 'stars', 'desc')

    print(f'Adding top {limit} most starred repositories to data.csv')

    with open('data.csv', 'w', newline='') as csvfile:
        fieldnames = ['name', 'url', 'stars']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()

        count = 0
        for repo in result:
            if(count > limit):
                break
            writer.writerow(
                {'name': repo.name, 'url': repo.clone_url, 'stars': repo.stargazers_count})
            count += 1

    print(f'DONE! Added top {limit} most starred repositories to data.csv')


if __name__ == '__main__':
    g = Github(ACCESS_TOKEN)
    search_github(keyword)
