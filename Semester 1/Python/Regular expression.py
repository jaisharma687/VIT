import re
x='star wars'
if re.match('.*s$', x):
    print('Matched')
else:
    print(' Star wars')

# ^ prefix will indicate starting and 
# .* will consider any number of letters before the given letter
# # $ suffix will indicate ending

import re
x='abvde'
if re.match('^abvde$',x):
    print('KBC')
    
import re
if re.match('[a-g]..d','food'):
    print('Matched')

import re
if re.match('[a-gA-G]..d','food'):
    print('Matched')

import re
if re.match('[a-gA-G0-9]..d','food'):
    print('Matched')


# giving ^ inside [] will exclude the characters inside []

# if '' is not given in pattern then ascii code of that character is considered