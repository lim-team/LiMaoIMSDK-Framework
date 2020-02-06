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
  s.source = { :git => "https://github.com/lim-team/LiMaoIMSDK-Framework.git", :tag => "#{s.version}" }

  s.ios.deployment_target    = '8.0'
  s.ios.preserve_paths       = 'ios/LiMaoIMSDK.framework'
  s.ios.public_header_files  = 'ios/LiMaoIMSDK.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'ios/LiMaoIMSDK.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/LiMaoIMSDK.framework'
end
