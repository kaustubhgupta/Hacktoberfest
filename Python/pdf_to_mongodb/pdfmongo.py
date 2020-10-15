import tabula
import pandas as pd
from pymongo import MongoClient

pdf_path = "data.pdf";

dfs = tabula.read_pdf(pdf_path, pages="all" );

client = MongoClient();

db = client['pdf_tables'];
collection_id = 1;

removeChars = lambda string : ''.join(e for e in string if e.isalnum());

for df in dfs:
    df.rename(removeChars, axis='columns', inplace=True);
    df.reset_index(inplace=True);
    data = df.to_dict("records");
    collection = db['table_' + str(collection_id)];
    collection.insert_many(data);
    collection_id += 1
