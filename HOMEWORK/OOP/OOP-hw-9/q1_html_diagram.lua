+--------------------+       +----------------------+        +------------------+             +------------------+
|       Writer       |       |      HTMLWriter      |        |    Doc_element   |             | vector<Doc_elem> |
+--------------------+       +----------------------+        +------------------+             +------------------+
|  <<abstract>>      |       |   <<final>>          |        |                  |             |                  |
|  +write(str: str)  | ----> |   +write(str: str)   |        |  -name_: string  |             |  -data_: vector  |
|  +destructor()     |       |    -ofs_: ofstream&  |        |                  +-------------+                  |                
|                    |       |                      |        |  -children_: vector<Doc_elem>                     |
+--------------------+       +----------------------+        |  +write_document(w: const Writer&)const           | 
                                                             |  +write_to(w: const Writer&, lv: int)const        |
                                                             |  text(t: str): Doc_elem                           |
                                                             |  Doc_elem(n: str)                                 |
                                                             |  Doc_elem(n: str, children: vector<Doc_elem>)     |
                                                             +---------------------------------------------------+
