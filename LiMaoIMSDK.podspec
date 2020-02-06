Pod::Spec.new do |s|
  s.name = 'LiMaoIMSDK'
  s.version = '0.1.0'
  s.summary = 'A short description of LiMaoIMSDK.'
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"tangtaoit"=>"412145540@qq.com"}
  s.homepage = 'https://github.com/lim-team/LiMaoIMSDK-Framework'
  s.description = '狸猫IM是一款简单，高效，支持完全私有化的即时通讯.'
  s.frameworks = ["UIKit", "MapKit"]
  s.libraries = ["opencore-amrnb", "opencore-amrwb", "vo-amrwbenc"]
  # s.xcconfig = {"LIBRARY_SEARCH_PATHS"=>"/work/projects/limao/LiMaoIMSDK/LiMaoIMSDK/Classes/Vendor/arm/lib"}
  s.source = { :http => "http://49.235.59.182:8888/LiMaoIMSDK-Framework-0.1.0.zip" }

  s.ios.deployment_target    = '8.0'
  s.ios.vendored_frameworks  = 'ios/LiMaoIMSDK.framework'
end