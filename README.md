
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
>