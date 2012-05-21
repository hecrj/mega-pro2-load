require "rainbow"

time = Time.now

puts "running    ".color(:yellow) + "Autodetecting executable..."

exe = Dir["*.exe"][0]

if(exe.nil?)
	puts "error      ".color(:red) + "No executable found..."
	exit
else
	puts "detected   ".color(:green) + exe
end

stats = {:passed => 0, :failed => 0}

ARGV.each do |testDir|
	puts "Running tests in " + testDir.color(:magenta) + ":"

	Dir.glob("#{testDir}/*.{txt,dat}") do |filename|
		puts "running    ".color(:yellow) + "#{filename}"

		basename = File.basename(filename, File.extname(filename))

		`./#{exe} < #{filename} > #{basename}.out`

		outname = Dir.glob("#{testDir}/#{basename}.{out,sal}")[0]

		if outname.nil?
			puts "not found  ".color(:magenta) + "#{testDir}/#{basename}.out"
			puts "not found  ".color(:magenta) + "#{testDir}/#{basename}.sal"
			next
		end

		differences = `diff -Bbw #{basename}.out #{outname}`

		if differences.empty?
			puts "passed     ".color(:green) + outname
			File.delete("#{basename}.out")

			stats[:passed] += 1
		else
			puts "  " + "failed     ".color(:red) + outname
			
			stats[:failed] += 1
		end
	end
end

puts "#{stats[:passed] + stats[:failed]} tests run".color(:yellow) + ", " +
     "#{stats[:passed]} passed".color(:green) + ", " +
     "#{stats[:failed]} failed".color(:red)

puts "Elapsed time (HH:MM:SS:LL): ".color(:magenta) + Time.at(Time.now - time).gmtime.strftime('%H:%M:%S:%L')