     +--------------------+
     |      Writer        |
     +--------------------+
     | write(str: string) |
     +--------------------+
              ^
              |
              |
     +--------------------+
     |     HTMLWriter     |
     +--------------------+
     | write(str: string) |
     +-----------------+---

     +---------------------------------------------------------+
     |                      Doc_element                        |
     +---------------------------------------------------------+
     | name_: string                                           |
     | children_: vector<Doc_element>                          |
     +---------------------------------------------------------+
     | write_document(w: Writer) const                         |
     | write_to(w: Writer, lv: int) const                      |
     +---------------------------------------------------------+
     | + text(t: string) : Doc_element                         |
     | + Doc_element(n: string)                                |
     | + Doc_element(n: string, children: vector<Doc_element>) |
     +---------------------------------------------------------+
