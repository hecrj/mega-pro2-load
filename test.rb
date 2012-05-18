require "rainbow"

puts "running    ".color(:yellow) + "Autodetecting executable..."

exe = Dir["*.exe"][0]

if(exe.nil?)
	puts "error      ".color(:red) + "No executable found..."
	exit
else
	puts "detected   ".color(:green) + exe
end

passed, failed = 0, 0

ARGV.each do |testDir|
	puts "Running tests in " + testDir.color(:magenta) + ":"

	Dir.glob("#{testDir}/*.{txt,dat}") do |filename|
		puts "running    ".color(:yellow) + "#{filename}"

		basename = File.basename(filename, File.extname(filename))

		`./#{exe} < #{filename} > #{basename}.out`

		status = true

		outname = Dir.glob("#{testDir}/#{basename}.{out,sal}")[0]

		if outname.nil?
			puts "not found  ".color(:magenta) + "#{testDir}/#{basename}.out"
			puts "not found  ".color(:magenta) + "#{testDir}/#{basename}.sal"
			next
		end

		differences = `diff -Bbw #{basename}.out #{outname}`

		if differences.empty?
			puts "passed     ".color(:green) + outname
			passed += 1
		else
			puts "  " + "failed     ".color(:red) + outname
			failed += 1
		end

		File.delete("#{basename}.out") if differences.empty?
	end
end

puts "#{passed + failed} tests run".color(:yellow) + ", " + "#{passed} passed".color(:green) + ", " + "#{failed} failed".color(:red)