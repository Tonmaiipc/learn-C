##Exercise 17

(1) Declare structure

```C
struct Address {
  int id;
  int set;
  char *name[MAX_DATA];
  char *email[MAX_DATA];
};

struct Database {     /* creating database of many struct address */
  struct Address rows[MAX_ROWS];
};

struct Connection {     /* connect the address of the file with the address of the database */
  FILE *file
  struct Database *db
};  /* there could be many files with different databases */
```

(3) main function of the program

```C
int main (int argc, char *argv[])
{
  // check if given command is correct.
  if (argc<3) die("USAGE: ex17 <dbfile> <action> [action params]");
  
  // declare input parameters
  char *filename = argv[1]; /* string */
  char action = argv[2][0]; /* character */
  
  // create a pointer variable "*conn", type = struct Connection, point to "file" and "database"
  struct Connection *conn = Database_open(filename, action);
  
  // initiate id at 0 for some functions (eg. get, load etc.) and check if id not more than max database
  int id = 0;
  if(argc > 3) id = atoi(argv[3]);
  if (id >= MAX_ROWS) die("There's not that many records.");
  
  // now conn* has been create, 
  // if create new database, conn->file is loaded but conn->db is still null
  // if load database both conn->file and conn->db are assigned.
  
  
    // then, this allow user to select actions
  switch(action) {
    // 'c' creates new "empty" database on a filename
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;
    
    case 'g':
      if(argc != 4) die("Need an id to get");
      
      Database_get(conn, id);
      break;
      
    case 's':
      if(argc != 6) die("Need id, name, email to set");
      
      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;
      
    case 'd':
      if(argc != 4) die("Need id to delete")
      
      Database_delete(conn, id); /* assign set = 0 */
      Database_write(conn); /* write the conn->db back to file at conn->file */
      // the name and email are still exist, but set = 0 
      // hence allow them to be written over.
      break;
      
      case 'l':
        Database_list(conn);
        break;
      default:
        die("Invalid action. c=create, g=get, s=set, d=del, l=list");
        
  }
```

(2) declare functions

Database_open
```C
struct Connection *Database_open(const char *filename, char mode) 
{
/* filename is declared as constant hence couldn't be changed later */
  
  // firstly create conn pointer structure with an allocated memory
  struct Connection *conn = malloc(sizeof(struct Connection));
  // if conn = 0 or NULL, it means conn points to nothing, 
  // and will activate die function to give error message.
  if(!conn) die("Memory Error")
  
  // create conn->db pointer which point to an allocated memory
  conn->db = malloc(sizeof(struct Database));
  if(!conn->db) die("Memory Error")
  
  // create conn->file pointer pointing to 
  // (1) an empty memory block to create new file
    if(mode == 'c') {
    conn->file = fopen(filename, "w");
  // (2) address of a file to be loaded
  } else {
      // open a file
      conn->file = fopen(filename, "r+");
      // load database from file into conn->db
      if (con->file) {
        Database_load(conn);
      } 
  }
  
  // if conn->file = NULL, report memory error
  if(!conn->file) die("Failed to open the file")
  
  // return struct conn of pointers pointing to file and database
  return conn;
}
```

Database_load
```C
void Database_load(struct Connection *conn) 
/* This function takes both conn->file and conn->db from *conn */
{
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  /* load 1 addresss each with size of `sizeof(struct Database)` 
  from file of conn->file into conn-> pointer 
  fread returns number of element loaded. */
  if(rc != 1) die("Failed to load database");
}
```

Database_create
```C
void Database_create(struct Connection *conn)
{
  // creating new database containing 100 rows of address
  int i = 0;
  for(i = 0; i < MAX_ROWS; i++) {
    // create row[i] with set = 0 for all id address (still empty) then set to conn->db
    struct Address addr = (.id = i, .set = 0);
    conn->db->rows[i] = addr;
  }
}
```
  
Database_write after create database, write conn->db into conn->file
```C
void Database_write(struct Connection *conn)
{
  rewind(conn->file); // start at the beginning of the file
  
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to write database")
  
  // After conn->db has been written to the file, file is needed to be flushed out of conn->file to prevent memory leakage
  rc = fflust(conn->file);
  if(rc == -1) die("Cannot flush database.");
}
```

Database_get to load a database and then print it
```C
void Database_get(struct Connection *conn, int id);
{
  // load id into *addr
  struct Address *addr = &conn->db->rows[id];
  
  // if addr-> = 1 , call Address_print(addr),   if addr-> = 0, the address isn't set yet.
  if(addr->set) {
    Address_print(addr);
  } else {
    die("ID is invalid");
  }
}
```

Address_print, to print address called by Database_get
```C
void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}
```

Database_set
```C
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  // addr pointer point to an address of specific id
  struct Address *addr = &conn->db->rows[id];
  if(addr->set) die("Already set, delete it first");
  
  // set addr.set = 1 so it can be call later to check if this id has been written
  addr->set = 1;
  
  char *res = strncpy(addr->name, name, MAX_DATA);
  if(!res) die("Name copy failed");
  
  res = strncpy(addr->email, email, MAX_DATA);
  if(!res) die("Email copy failed");
}

Database_delete
```C
void Database_delete(struct Connection *conn, int id)
{
  struct Address addr = (.id = id, .set = 0)
  conn->db->rows[id] = addr;
}
```

Database_list
```C
void Database_list(struct Connection *conn)
{
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = db->rows[i]
    
    if(cur->set) {
      Address_print(cur);
    }
  }
}

Die function
```C
void die(const char *message)
{
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  
  exit(1);
}
