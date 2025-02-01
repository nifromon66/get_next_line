
# GET_NEXT_LINE

By nifromon (Nicolas Fromont), student at 42 perpignan, France.
> ---
>
> ## DESCRIPTION
>
> This project goal is to add to your collection a really usefull function, but also to discover a surprising new element of C.
>
> This function goal is to return a line readed from a specified file descriptor. Which end goal is to be able to read an entire file after calling the function successively, and that's where our new friend : static variables, will act.
>
> ---
>
> ## INSTRUCTIONS
>
> - Function name : [get_next_line](get_next_line/get_next_line.c).
> - Prototype : `char   *get_next_line(int fd)`
> - Files to return :
>   - Mandatory :
>     - [get_next_line.h](get_next_line/get_next_line.h)
>     - [get_next_line.c](get_next_line/get_next_line.c)
>     - [get_next_line_utils.c](get_next_line/get_next_line_utils.c)
>   - If bonus :
>     - [get_next_line_bonus.h](get_next_line/get_next_line_bonus.h)
>     - [get_next_line_bonus.c](get_next_line/get_next_line_bonus.c)
>     - [get_next_line_utils_bonus.c](get_next_line/get_next_line_utils_bonus.c)
> - Allowed external functions : read() {fcntl.h}, malloc(), free() {stdlib.h}.
> - Libft allowed : No.
>
> ---
>
> ## STATIC VARIABLES
>
> Static variables have the property of preserving their value even after they are out of their scope, either being the program (if global) or the function they are declared in. Hence, a static variable is a variable that preserves its previous value across multiple function calls, and not being initialized again.
>
> Here is the syntax of a static variable :
>
> - `static data_type var_name = var_value;`
>
> Static variables are allocated memory in the data segment, not the stack segment. Which makes their persistence ability. They are initialized as 0 if not explicitely initialized otherwise and can only be initialized using constant literals.
>
> Static variables are also widely used in C to limit the scope of a function to the file.
>
> Static variables should not be declared inside a structure. The reason being in C, compilers requires the entire structure members to be placed together and that memory allocation for structure members should be contiguous. It is possible to declare a structure inside a function (stack segment) or allocate memory dynamically(heap segment) or it can be even global(BSS or data segment).
>
> Whatever the case, all structure members should be contained inside the same memory segment because the value for the structure element is fetched by counting the offset of the element from the beginning adress of the structure. Separating out one member alone to a data segment defeats the purpose of a structure and so it is possible to have a entire structure as static, but not an individual member.
>
> ---
>
> ## FUNCTIONS
>
> - ### Main functions
>      - [gnl_inventory](get_next_line/get_next_line.c#L45)
>         - Prototype : `int    gnl_inventory(t_gnl **store, int fd);`
>         - Description : It reads data from the file descriptor 'fd' in chunks of 'BUFFER_SIZE' bytes and stores it in the linked list pointed to by 'store'. It continues reading until a newline character is found or an error occurs.
>         - Return Value : Returns the number of bytes read 'bill' upon success, 0 if there is no more data to read in the file. Or a -1 in case of an error.
>      - [gnl_stock_replenishment](get_next_line/get_next_line.c#L69)
>         - Prototype : `void   gnl_stock_replenishment(t_gnl **store, char *product);`
>         - Description : It appends a new node containing the data of 'product' to the end of the linked list pointed to by 'store'. This function is used to manage and accumulate read data chunks for later processing.
>         - Return Value : None.
>      - [gnl_fetch_queue](get_next_line/get_next_line.c#L86)
>         - Prototype : `void   gnl_fetch_queue(t_gnl *store, char **queue);`
>         - Description : It extracts and consolidates the stored data from the linked list 'store' into a newly allocated string 'queue' which represents a line.
>         - Return Value : None.
>      - [gnl_cutting_in](get_next_line/get_next_line.c#L100)
>         - Prototype : `void   gnl_cutting_in(t_gnl **store);`
>         - Description : It trims the stored data in 'store' by removing the processed portion up to and including the first found newline character (\n). It retains only the remaining content after the newline and updates the store accordingly to prepare for the next function call.
>         - Return Value : None.
> - ### Utils functions
>      - [gnl_lst_search_newline](get_next_line/get_next_line_utils.c#L16)
>         - Prototype : `int    gnl_lst_search_newline(t_gnl *store);`
>         - Description : It scans the linked list pointed to by 'store' to check if a newline character (\n) exists within the stored data.
>         - Return Value : 1 if a newline is found or 0 if no newline were found or if 'store' is NULL.
>      - [gnl_lst_to_str](get_next_line/get_next_line_utils.c#L45)
>         - Prototype : `void   gnl_lst_to_str(t_gnl *store, char *queue);`
>         - Description : It converts the contents of the linked list pointed to by 'store' into a single string 'queue'. It copies characters sequentially, stopping when a newline character is encountered. ensuring that 'queue' contains a complete line.
>         - Return Value : None.
>      - [gnl_lst_linelen](get_next_line/get_next_line_utils.c#L71)
>         - Prototype : `int    gnl_lst_linelen(t_gnl *store);`
>         - Description : It calculates the total length of a line stored in the linked list pointed to by 'store'. It counts characters sequentially until it encounters a newline (\n) or reaches the end of the stored data.
>         - Return Value : The total number of characters in the line, including the newline character (\n) if found, or 0 if 'store' is NULL, or the total lenght of avaible data if no newline is found.
>      - [gnl_free_store](get_next_line/get_next_line_utils.c#L94)
>         - Prototype : `void   gnl_free_store(t_gnl **store, t_gnl *clean_store, char *product);`
>         - Description : It frees the memory used by linked list 'store', then updates it with clean store if it contains data. Otherwise, it deallocates 'clean_store' and product.
>         - Return Value : None.
> ---
