# zjy-sql

## Initial Project Definition
### Purpose
- To create an in-memory SQL database written in rust
- In college, I developed an in-memory SQL database in Python, which allowed me to explore the nuanced features of the language while gaining a deeper understanding of the inner workings of a DBMS—from query parsing and tokenization to optimization and executing the plan against the internal data store
- I am using this project to
  1. Write an impl that is much more performant while having a lower memory footprint (Due to Rust's low-level control over system resources and its performance advantages compared to Python)
  2. As a mechanism to guide my deeper exploration of Rust language
  3. To explore query optimization strategies that were beyond the scope of my initial impl (The furthest we got was implementing optimizations for Sort-Merge rather than Nested Loop joins)

### Outline
1. Identify a Parser: Choose an initial subset of SQL grammar that the system will support and define the initial subset of data types.
2. Develop SQL Query Parsing and Tokenization: Build routines to tokenize and parse SQL queries according to the selected grammar.
3. Define Types, Schemas, and Tabular Data Handling: Identify how to handle data types, schemas, and tabular data storage.
4. Develop Interfaces:
- Create interfaces for handling types, including type validation for incoming data.
- Develop schema enforcement mechanisms.
- Design a structure to store tabular data. (Consider referencing Polars for efficiency but aim for a fine-grained representation to allow for future query optimization.)
- Define utils that can populate data from a variety of source formats (parquet, json, csv)
- Define utils that can be used to write data to a variety of file formats (parquet, json, csv)
5. Develop Routines for Query Execution: Implement the necessary routines to perform operations supported by the condensed grammar, ensuring the use of optimizations during query execution.
6. Iterative Expansion: Gradually expand the supported SQL grammar, types, and optimizations, improving functionality and performance iteratively.
