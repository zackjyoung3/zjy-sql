# zjy-sql

## Initial Project Definition

### Purpose

- **Project Goal:**  
  To create an in-memory SQL database written in **C++**.

- **Background:**  
  In college, I developed an in-memory SQL database in Python. That project allowed me to dive deep into various aspects of DBMS implementation—from query parsing and tokenization to optimization and executing plans against an internal data store.

- **Objectives for the C++ Implementation:**  
  1. **Performance & Memory Efficiency:**  
     Leverage C++'s low-level control and high-performance capabilities to build a more efficient implementation with a lower memory footprint.
  
  2. **Deepening Language Mastery:**  
     Use this project as an opportunity to deepen my understanding of modern C++ practices, design patterns, and advanced features.
  
  3. **Advanced Query Optimization:**  
     Explore query optimization strategies that were beyond the scope of my previous Python implementation. The initial Python version only implemented basic optimizations (e.g., for Sort-Merge rather than Nested Loop joins). With C++, there is room to push these optimizations further.

### Outline

1. **Parser Identification:**  
   - **Define a Subset of SQL Grammar:**  
     Choose an initial subset of SQL grammar that the system will support.
   - **Select Data Types:**  
     Determine the initial set of data types that the database will handle.

2. **SQL Query Parsing and Tokenization:**  
   - **Tokenization:**  
     Develop routines to tokenize SQL queries.
   - **Parsing:**  
     Build a parser that processes the tokenized queries based on the defined SQL grammar.

3. **Data Types, Schemas, and Tabular Data Handling:**  
   - **Type Handling:**  
     Define how various data types are represented and validated in the system.
   - **Schema Enforcement:**  
     Develop mechanisms to enforce schema rules on the input data.
   - **Tabular Data Storage:**  
     Design an efficient, in-memory data structure to store tables.  
     *(Hint: Consider lightweight data structures that can later facilitate query optimization.)*

4. **Developing Interfaces and Utilities:**  
   - **Interface Design:**  
     Create clear interfaces for type handling, schema enforcement, and data manipulation.
   - **Data I/O Utilities:**  
     Implement utilities for:
     - Populating data from different source formats (e.g., Parquet, JSON, CSV)
     - Writing data back to various file formats (e.g., Parquet, JSON, CSV)
   - **Reference Implementations:**  
     Look into existing libraries (such as Apache Arrow for columnar data representation) that might serve as inspiration or components.

5. **Query Execution Engine:**  
   - **Execution Routines:**  
     Develop routines that execute queries based on the condensed SQL grammar.
   - **Optimization Techniques:**  
     Integrate advanced optimization strategies during query execution to improve performance.

6. **Iterative Expansion and Refinement:**  
   - **Incremental Development:**  
     Gradually expand the supported SQL grammar, additional data types, and optimizations.
   - **Performance Tuning:**  
     Continuously profile and refine the implementation to ensure high performance and efficient memory usage.
   - **Feature Expansion:**  
     Over time, incorporate more complex SQL features and query execution paths.
