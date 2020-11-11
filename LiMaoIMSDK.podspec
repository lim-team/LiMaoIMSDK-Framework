Pod::Spec.new do |s|
  s.name = 'LiMaoIMSDK'
  s.version = '0.2.3'
  s.summary = '狸猫IM是一款简单，高效，支持完全私有化的即时通讯.'
  s.license = {"type"=>"MIT", "file"=>"ios/LICENSE"}
  s.authors = {"tangtaoit"=>"412145540@qq.com"}
  s.homepage = 'https://github.com/lim-team/LiMaoIMSDK-Framework'
  s.description = '狸猫IM是一款简单，高效，支持完全私有化的即时通讯，提供群聊，点对点通讯解决方案'
  s.frameworks = ["UIKit", "MapKit","AVFoundation"]
  # s.libraries = ["opencore-amrnb", "opencore-amrwb", "vo-amrwbenc"]
  s.ios.libraries = ['c++','sqlite3','z']
  # s.xcconfig = {"LIBRARY_SEARCH_PATHS"=>"/work/projects/limao/LiMaoIMSDK/LiMaoIMSDK/Classes/Vendor/arm/lib"}
  # s.source = { :git => "https://github.com/lim-team/LiMaoIMSDK-Framework.git",:tag => "#{s.version}" }
  s.source = { :git => "https://github.com/lim-team/LiMaoIMSDK-Framework.git",:tag => "#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, '9.0'
  s.ios.deployment_target    = '9.0'
    s.pod_target_xcconfig = {
      'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # s.resource_bundles = {
  #    'LiMaoIMSDK' => ['ios/Assets/*.png','ios/Assets/Migrations/*']
  # }
  # s.ios.preserve_paths       = 'ios/LiMaoIMSDK.framework'
  # s.ios.public_header_files  = 'ios/LiMaoIMSDK.framework/Versions/A/Headers/*.h'
  s.resource             = 'ios/LiMaoIMSDK.framework/Versions/A/Resources/LiMaoIMSDK.bundle'
  s.vendored_frameworks  = 'ios/LiMaoIMSDK.framework'
#  s.static_framework = true
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }  
  s.vendored_libraries = ['ios/libvo-amrwbenc.a','ios/libopencore-amrnb.a','ios/libopencore-amrwb.a']
  # s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => '' }
  s.dependency 'CocoaAsyncSocket', '~> 7.6.2'
  s.dependency 'FMDB', '~>2.7.2'
end
