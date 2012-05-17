require "rainbow"

puts "running    ".color(:yellow) + "Autodetecting executable..."

exe = Dir["*.exe"][0]

if(exe.nil?)
	puts "error      ".color(:red) + "No executable found..."
	exit
else
	puts "detected   ".color(:green) + exe
end

puts "Enter the directory you want to test: "
testDir = gets.chomp

puts "Running tests in " + testDir.color(:blue) + ":"

passed = 0
failed = 0

Dir.glob("#{testDir}/*.{txt,dat}") do |filename|
	puts "running    ".color(:yellow) + "#{filename}"

	basename = File.basename(filename, File.extname(filename))

	`./#{exe} < #{filename} > #{basename}.out`

	status = true

	Dir.glob("#{testDir}/#{basename}.{out,sal}") do |outname|
		differences = `diff -Bbw #{basename}.out #{outname}`

		if(differences.empty?)
			puts "  " + "passed     ".color(:green) + outname
			passed += 1
		else
			puts "  " + "failed     ".color(:red) + outname
			failed += 1
		end

		passed += 1 if differences.empty?
		status = differences.empty? if status
	end

	puts "" + (status ? "passed     ".color(:green) : "failed     ".color(:red)) + filename

	File.delete("#{basename}.out") if status
end

puts "#{passed + failed} tests run".color(:yellow) + ", " + "#{passed} passed".color(:green) + ", " + "#{failed} failed".color(:red)