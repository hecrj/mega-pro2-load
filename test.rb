puts "Autodetecting executable..."

exe = Dir["*.exe"][0]

if(exe.nil?)
	puts "No executable found..."
	exit
else
	puts "Autodetected executable: " + exe
end

puts "Enter the directory you want to test: "
testDir = gets.chomp

puts "Running tests in " + testDir + ":"

Dir.glob("#{testDir}/*.{txt,dat}") do |filename|
	puts "Running " + filename

	`./#{exe} < #{filename} > temp.out`

	basename = File.basename(filename, File.extname(filename))

	puts "Checking outputs for " + filename

	Dir.glob("#{testDir}/#{basename}.{out,sal}") do |outname|
		puts "Checking " + outname

		differences = `diff -Bbw temp.out #{outname}`

		if(not differences.empty?)
			puts "Difference detected!"
			exit
		end
	end

	File.delete("temp.out")
end

puts "All tests passed correctly!"
