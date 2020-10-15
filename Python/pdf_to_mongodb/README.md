# TOP ✨ hacktoberfest 👨🏻‍💻 PDF to MongoDB

### 🛠 Setup before runing code
  - This project uses Tabula. If you haven't installed PyGithub then run ```pip install tabula-py```
  - This project uses PyMongo. If you haven't installed PyMongo, then run ```pip install pymongo```
  - Make sure you have Mongo installed and running locally.
  - That's it!

### 🏁 Running the project
  - Just run pdfmongo.py using python3
  - Running main.py will insert the tables from the sample pdf in the folder to different collections in the local db named "pdf_tables".
  - The collections will be named table_1, table_2 and so on.

### 💡About the PDF file
  - The script correctly picks simple tables from pdf files.

### ⚙️ Changes you can make
  - You can change the pdf file being inserted in mongodb.
