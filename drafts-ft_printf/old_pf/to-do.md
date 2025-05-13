# To Do list

`23/04`

- document flag hierarchy and specify behaviours and synergies;
- create struct with flags stored maybe?
- see git group project;

---

Understand and document printf's behaviour. Mainly how it handles wrong input and how flags work.

create a function that parses(?) through the string as soon as a '%' sign is found and:
 - detects **flags**:
  - which flags should it detect
  - flag's behaviour
  - how many characters constitute said flag (to read and skip)
  - what conversion characters interact with which flags

### **NOTE**: flags

a function only for flags that is called at the start of `percent_scanner`, immediately filtering what *conv_char* it is going to interact with;

 - detects which conversion character (conv_char) is being called and if it matches the type of argument we are sending to the function

### **NOTE**: %

`ft_percent_scanner`(name WIP) is called each time a conversion needs to happen, i.e.: each time a '%' sign is read.

the conversion happens only:
- if there is a *Valet* to be processed and
- if the type of the *Valet* matches the *conv_char* we are parsing through;
- if the flag between the '%' and the conv_char is valid to said char (this might be wrong, need to test flags)

-----

## what the ft_printf function should do

Check if number of conversions in *s* meets the number of Valets.

Check if each conversion matches the corresponding Valet type. Placement/order dependant.
As soon as one doesn't, either error and program stops OR gives out a warning if input is accepted but not exactly correct.

Flag check here maybe.

It should [split] the string given as a fixed argument when a '%' followed by *flag* (optional) and a *conv_char* is met.

1. Store said string under a `char **buffer` (like with ft_split) (x number of mallocs)

**OR**

2. Calculate buffer size for a single char _string_ by determing length of Valets (1 malloc maybe)

In both methods we write the strings (or characters in the string) and converted Valets into the buffer
in accordance to their positions. Because the checks for incorrect inputs were already well ... checked
we only have to handle incorrect memory allocation (`ft_free_split` basically).

When buffer string(s) is ready, we:
- call `ft_putstr` to write into STDOUT;
- free the allocated memory;
- free the va_list with `va_end()`;
