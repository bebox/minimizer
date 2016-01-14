import sys, time, resource

# read console arguments
input_file = sys.argv[1]
w = int(sys.argv[2])
k = int(sys.argv[3])
l = w+k-1

# array to store minimizers
minimizers = []
    
# function 'find minimizer within a substring'
def minimizer(str):
  array = []

  for i in range (0, len(str)-k+1):
    array.append(str[i:i+k])
    
  return min(array)

# function 'find left-end minimizers'
def left_end(str):
  array = []
  
  for i in range (k, l):
    min_seed = minimizer(str[0:i])
    array.append(min_seed)
    
  return array
  
# function 'find right-end minimizers'
def right_end(str):
  array = []
  
  for i in range (0, l-k):
    min_seed = minimizer(str[i:l])
    array.append(min_seed)
    
  return array
  
# function 'remove duplicates'
def remove_duplicates(array):
  new_array = []
  
  for str in array:
    if (not new_array or new_array[-1] != str):
      new_array.append(str)
      
  return new_array
  
# ---------------------------------main------------------------------------------

time_start = time.clock()

# read input file
with open (input_file, "r") as f_in:
  sequence = f_in.read().replace('\r', '').replace('\n', '')

seq_len = len(sequence)
  
# find left-end minimizers
left_minimizers = left_end(sequence[0:l])
for str in left_minimizers:
  minimizers.append(str)

# find interior minimizers
for i in range (0, seq_len-l+1):
  min_seed = minimizer(sequence[i:i+l])
  minimizers.append(min_seed)
  
# find right-end minimizers
right_minimizers = right_end(sequence[seq_len-l+1:seq_len])
for str in right_minimizers:
  minimizers.append(str)
  
# remove duplicates
minimizers = remove_duplicates(minimizers)

# write minimizers to file
f_out = open('output.txt','w')
for item in minimizers:
  f_out.write("%s\n" % item)
f_out.close()

# calculate time and memory consumption
duration = time.clock() - time_start
memory  = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
  
# print out variables
print "Finished!"
print "Duration: ", duration, "seconds"
print "Memory consumption: ",  memory,  "KB"
