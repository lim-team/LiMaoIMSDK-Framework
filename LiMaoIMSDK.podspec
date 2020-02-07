Pod::Spec.new do |s|
  s.name = 'LiMaoIMSDK'
  s.version = '0.1.12'
  s.summary = '狸猫IM是一款简单，高效，支持完全私有化的即时通讯.'
  s.license = {"type"=>"MIT", "file"=>"ios/LICENSE"}
  s.authors = {"tangtaoit"=>"412145540@qq.com"}
  s.homepage = 'https://github.com/lim-team/LiMaoIMSDK-Framework'
  s.description = '狸猫IM是一款简单，高效，支持完全私有化的即时通讯，提供群聊，点对点通讯解决方案'
  s.frameworks = ["UIKit", "MapKit","AVFoundation"]
  s.libraries = ["opencore-amrnb", "opencore-amrwb", "vo-amrwbenc"]
  s.ios.libraries = 'c++'
  # s.xcconfig = {"LIBRARY_SEARCH_PATHS"=>"/work/projects/limao/LiMaoIMSDK/LiMaoIMSDK/Classes/Vendor/arm/lib"}
  # s.source = { :git => "https://github.com/lim-team/LiMaoIMSDK-Framework.git",:tag => "#{s.version}" }
  s.source = { :git => "https://github.com/lim-team/LiMaoIMSDK-Framework.git",:tag => "#{s.version}" }

  s.ios.deployment_target    = '8.0'
  # s.resource_bundles = {
  #   'LiMaoIMSDK' => ['ios/Assets/*.png','ios/Assets/Migrations/*']
  # }
  # s.ios.preserve_paths       = 'ios/LiMaoIMSDK.framework'
  # s.ios.public_header_files  = 'ios/LiMaoIMSDK.framework/Versions/A/Headers/*.h'
  # s.ios.resource             = 'ios/LiMaoIMSDK.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/LiMaoIMSDK.framework'
  s.vendored_libraries = 'ios/*.{a}'
  # s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => '' }
  s.dependency 'CocoaAsyncSocket', '~> 7.6.2'
  s.dependency 'FMDB', '~>2.7.2'
end
