#remove duplicates from array
def remove_duplicates(array)
  dup_array = []
  for str in array
    if (dup_array.length == 0 or dup_array[-1] != str)
      dup_array.push(str)
    end
  end
  return dup_array
end

#find minimizer on left end of genome
def left_end(str, k, l)
  array = []
  (k..l-1).each do |i|
    array.push(min_substring(str[0..i-1], k))
  end
  return array
end

#find minimizer on right end of genome
def right_end(str, k, l)
  array = []
  (0..(l-k-1)).each do |i|
    array.push(min_substring(str[i..l-1], k))
  end
  return array
end

#find minimal substring inside of window
def min_substring (str, k)
  array = []
  (0..(str.length-k)).each do |i|
    array.push(str[i..(i+k-1)])
  end
  min_array = array.sort
  return min_array[0]
end

#main
#console line arguments and input read
file_name = ARGV[0]
w = ARGV[1].to_i
k = ARGV[2].to_i
l = w + k - 1
start = Time.now
inputFile = File.open(file_name, "r")
input = inputFile.read.gsub("\n","").gsub("\r","")
inputFile.close

minimizers = []

#find minimizer on left end
for str in left_end(input[0..l-1], k, l)
  minimizers.push(str)
end


#find minimizer
(0..(input.length-l)).each do |m|
  minimizers.push(min_substring(input[m..(m+l-1)], k))
end


#find minimizer on right end
for str in right_end(input[(input.length-l+1)..(input.length)], k, l)
  minimizers.push(str)
end

minimizers = remove_duplicates(minimizers)

#writing to file
outputFile = File.open("output.txt", "w")
  minimizers.each do |m|
	   outputFile.puts m
  end
outputFile.close

finish = Time.now

#total elapsed time
total_time = finish - start
puts "Total time elapsed: " + total_time.to_s + " seconds"

#total memory used
total_memory = `ps -o rss -p #{$$}`.strip.split.last.to_i
puts "Total memory usage: " + total_memory.to_s + "KB."
