# TOP ✨ hacktoberfest 👨🏻‍💻 Repositories to CSV

### 🛠 Setup before runing code
  - This project uses PyGithub. If you haven't installed PyGithub then run ```pip install PyGithub```
  - That's it!

### 🏁 Running the project
  - Just run main.py using python3
  - Running main.py will create a **data.csv** file containing all the latest search results

### 💡About the CSV file
  - The first line will shows the properties of each line of csv data
  - By default that is **Name of repository, url/link, stars count**
  - The **data.csv** file contains the result sorted by no of stars.
  - Number of result in the csv file will depend on the value in **limit** variable
  - The results in the csv file is **overwritten** every time you run the program

### ⚙️ Changes you can make
  - After import statements there are two variables **limit** and **keyword** you can change their values according to your desired results.

### 💻 Troubleshooting
  - Make sure you have installed **PyGithub** as mentioned in the setup above.
  - **ACCESS_TOKEN** might stop working as Github Search API has limit so you ca follow the following steps to fix,
    - Log in to your github account.
    - Go to "Github Settings / Developer settings"
    - Generate a new Personal access token by checking the public_repo box under repo and then click Generate token.
    - Replace the **ACCESS_TOKEN** to the new one.
