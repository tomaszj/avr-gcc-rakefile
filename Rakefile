require 'rake'
require 'rake/clean'

mcu = "attiny85"

SOURCE_FILES = FileList.new("*.c")
object_files = SOURCE_FILES.pathmap("build/%X.o")

directory "build"

task :default => ["build/main.hex"]

file 'build/main.hex' => 'build/main.elf' do |task|
  sh "avr-objcopy -j .text -j .data -O ihex #{task.source} #{task.name}"
end

CLOBBER << "build/main.hex"

file 'build/main.elf' => object_files do |task|
  sh "avr-gcc -g -mmcu=#{mcu} -o #{task.name} #{task.prerequisites.join(" ")}"
end

CLEAN.include("build/main.elf")

rule ".o" => [->(f) { source_for_obj_file(f) }, "build"] do |task|
  sh "avr-gcc -g -mmcu=#{mcu} -Os -o #{task.name} -c #{task.source}"
end

CLEAN.include(object_files)

def source_for_obj_file(obj_file)
  SOURCE_FILES.detect{ |f| f.ext('') == obj_file.pathmap("%{^build/,}X")}
end

