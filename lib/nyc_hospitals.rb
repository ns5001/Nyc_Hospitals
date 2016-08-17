require_relative "./nyc_hospitals/version"
require_relative "./nyc_hospitals/cli"
require "./lib/scraper"
require 'pry'

class NycHospitals::NycHospitals
  attr_accessor :master_hash

  def initialize(brooklyn, staten_island, manhattan, bronx, queens)
    self.master_hash = {}
    self.master_hash[:brookyln] = brooklyn
    self.master_hash[:queens] = queens
    self.master_hash[:staten_island] = staten_island
    self.master_hash[:bronx] = bronx
    self.master_hash[:manhattan] = manhattan
    main_menu
  end

  def main_menu
    puts " "
    puts "Welcome! You can view every hospital in New York City."
    puts " "
    puts "Choose from the menu below:"
    puts "   ----- ------ -----   "
    user_input = ""
    while true
      puts "Search Hospital by borough - 1"
      puts "Search Hospital by name - 2"
      puts "Search Hospital by type - 3"
      puts "Exit - 4"
      puts " "

      user_input = gets.to_s.delete("\n")
      case user_input
      when "1"
        hospital_by_borough
      when "2"
        hospital_by_name
      when "3"
        hospital_by_type
      when "4"
        puts " "
        puts "Thank you! See you soon!"
        puts " "
        exit
      else
        puts " "
        puts  "Sorry please try again"
        puts " "
      end
    end
  end

   def list_hospital(hospital)
     puts " "
     puts "   ----- ------ -----   "
     puts "Name = #{hospital[1][:name]}"
     puts "Type = #{hospital[1][:type]}"
     puts "Phone Number = #{hospital[1][:phone_number]}"
     puts "Address = #{hospital[1][:address].split("\"")[3]} #{hospital[1][:address].split("\"")[7]} #{hospital[1][:address].split("\"")[11]} #{hospital[1][:address].split("\"")[15]}"
     puts "   ----- ------ -----   "
     puts " "
   end

  def hospital_by_type
    puts " "
    puts "What type of hospital are you looking for? Enter your choice from the following menu:"
    puts " "
    user_input = ""
    while user_input != "5"
      puts "Acute Care Hospital - 1"
      puts "Nursing Home - 2"
      puts "Diagnostic & Treatment Center - 3"
      puts "Child Health Care - 4"
      puts "Return to main menu - 5"
      puts " "
      user_input = gets.delete("\n")

      case user_input
      when "1"
        search_for_type("Acute Care Hospital")
      when "2"
        search_for_type("Nursing Home")
      when "3"
        search_for_type("Diagnostic & Treatment Center")
      when "4"
        search_for_type("Child Health Center")
      when "5"
        puts "Returning to main menu"
        puts "   ----- ------ -----   "
        puts " "
      else
        puts " "
        "Sorry please try again"
        puts " "
      end
    end
  end

  def search_for_type(type)
    self.master_hash.each do |borough|
      borough[1].each do |hospital|
        if hospital[1][:type] == type
          list_hospital(hospital)
        end
      end
    end
  end

  def hospital_by_name
    puts " "
    puts "Please enter name of the Hospital:"
    name = gets.delete("\n")
    i = 0
    self.master_hash.each do |borough|
      borough[1].each do |hospital|
        if hospital[1][:name] == name
          i += 1
          list_hospital(hospital)
        end
      end
    end

    if i < 1
      puts " "
      puts "Sorry no hospital was found by provided name. Returning to main menu"
      puts "   ----- ------ -----   "
      puts " "
    end
  end

  def hospital_by_borough
    borough = ""
    puts " "
    puts "   ----- ------ -----   "
    while borough != "6"
      puts "Please select your borough:"
      puts "Brooklyn - 1"
      puts "Staten Island - 2"
      puts "Bronx - 3"
      puts "Queens - 4"
      puts "Manhattan - 5"
      puts "Return to main menu - 6"

      borough = gets.to_s.delete("\n")

      case borough
      when "1"
        view_hospitals("brookyln".to_sym)
      when "2"
        view_hospitals("staten_island".to_sym)
      when "3"
        view_hospitals("bronx".to_sym)
      when "4"
        view_hospitals("queens".to_sym)
      when "5"
        view_hospitals("manhattan".to_sym)
      when "6"
        puts " "
        puts "Returning to main menu..."
        puts "   ----- ------ -----   "
        puts " "
      else
        puts " "
        puts "Sorry please try again"
        puts "   ----- ------ -----   "
        puts " "
      end
    end
  end

  def view_hospitals(borough)
    self.master_hash[borough].each do |hospital|
     puts " "
     puts "   ----- ------ -----   "
     puts "Name = #{hospital[1][:name]}"
     puts "Type = #{hospital[1][:type]}"
     puts "Phone Number = #{hospital[1][:phone_number]}"
     puts "Address = #{hospital[1][:address].split("\"")[3]} #{hospital[1][:address].split("\"")[7]} #{hospital[1][:address].split("\"")[11]} #{hospital[1][:address].split("\"")[15]}"
     puts "   ----- ------ -----   "
     puts " "
   end
  end


end
