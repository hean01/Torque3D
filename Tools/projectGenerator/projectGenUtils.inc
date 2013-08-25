<?php
//-----------------------------------------------------------------------------
// Copyright (c) 2012 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//
//	This file is now the 'API' which just wraps all the internal stuff nicely. 
//
//--------------------------------------------------------------------------------

function beginProject($name, $sharedConfig)
{
    // Set the game project name, this is what your game's exe/dll will be called
    setGameProjectName($name);
    
    if (T3DGenerator::$platform == "win32" && $sharedConfig)
        beginSolutionConfig( $name, '{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}' );

	
}

function endProject($sharedConfig)
{
    if (T3DGenerator::$platform == "win32" && $sharedConfig)
        endSolutionConfig();
}

function beginSolutionConfig( $name, $guid = '' )
{
	T3DGenerator::beginSolution( $name, $guid );
}

function addSolutionProjectRef( $pname )
{
	T3DGenerator::addSolutionProjectRef( $pname );
}

// Add a reference to an external project, this is used for WPF projects currently
// as adding all the various designer/xaml/stuff to the project generator is probably overkill
// However, it is nice to not have to add the project to the solution whenever you run the project generator
function addSolutionProjectRefExt( $pname, $ppath, $pguid )
{
    T3DGenerator::addSolutionProjectRefExt( $pname, $ppath, $pguid );
}

function endSolutionConfig()
{
	T3DGenerator::endSolution();
}

function setPlatform( $platform )
{      
   echo('   - Setting platform to: ' . $platform . "\n");
   
   T3DGenerator::$platform = $platform;
}

function includeLib( $libName )
{
    //echo( "GLP: " . T3DGenerator::getGeneratorLibsPath() . $libName . "\n" );
    
    T3DGenerator::includeLib( $libName );

}

function includeModule( $modName )
{
   require( T3DGenerator::getGeneratorModulesPath() . $modName . '.inc' );
}

function beginActiveXConfig( $lib_name, $guid = '', $gameDir = 'game', $output_name = '' )
{    
	T3DGenerator::beginActiveXConfig( $lib_name, $guid, $gameDir, $output_name );
}

function endActiveXConfig()
{
	T3DGenerator::endActiveXConfig();
}

function beginSafariConfig( $lib_name, $guid = '', $gameDir = 'game', $output_name = '' )
{    
	T3DGenerator::beginSafariConfig( $lib_name, $guid, $gameDir, $output_name );
}

function endSafariConfig()
{
	T3DGenerator::endSafariConfig();
}

function beginSharedLibConfig( $lib_name, $guid = '', $gameDir = 'game', $output_name = '' )
{    
	T3DGenerator::beginSharedLibConfig( $lib_name, $guid, $gameDir, $output_name );
}

function endSharedLibConfig()
{
	T3DGenerator::endSharedLibConfig();
}

function beginNPPluginConfig( $lib_name, $guid = '', $gameDir = 'game', $output_name = '' )
{    
	T3DGenerator::beginNPPluginConfig( $lib_name, $guid, $gameDir, $output_name );
}

function endNPPluginConfig()
{
	T3DGenerator::endNPPluginConfig();
}


function beginLibConfig( $lib_name, $guid = '', $gameDir = 'game', $output_name = '' )
{    
	T3DGenerator::beginLibConfig( $lib_name, $guid, $gameDir, $output_name );
}

function endLibConfig()
{
	T3DGenerator::endLibConfig();
}

function beginAppConfig( $app_name, $guid = '', $game_dir = 'game', $output_name = '' )
{    
   T3DGenerator::beginAppConfig( $app_name, $guid, $game_dir, $output_name );
}

function endAppConfig()
{
	T3DGenerator::endAppConfig();
}

function beginSharedAppConfig( $app_name, $guid = '', $game_dir = 'game', $output_name = '' )
{    
   T3DGenerator::beginSharedAppConfig( $app_name, $guid, $game_dir, $output_name );
}

function endSharedAppConfig()
{
	T3DGenerator::endSharedAppConfig();
}


function beginCSProjectConfig( $app_name, $guid = '', $game_dir = 'game', $output_name = '' )
{    
   T3DGenerator::beginCSProjectConfig( $app_name, $guid, $game_dir, $output_name );
}

function endCSProjectConfig()
{
	T3DGenerator::endCSProjectConfig();
}



///////////////////////

function beginModule( $name )
{
	T3DGenerator::beginModule( $name );
}

function endModule()
{
    T3DGenerator::endModule();
}

function addSrcDir( $dir, $recurse = false )
{
    //echo( "ADD SRC DIR: " . $dir . "\n" );

	T3DGenerator::addSrcDir( $dir, $recurse );
}

function addSrcFile( $file )
{
    //echo( "ADD SRC FILE: " . $file . "\n" );

	T3DGenerator::addSrcFile( $file );
}

function addEngineSrcDir( $dir )
{
    //echo( "ADD ENGINE SRC DIR: " . getEngineSrcDir() . $dir . "\n" );

 	addSrcDir( getEngineSrcDir() . $dir );
}

function addEngineSrcFile( $file )
{
    //echo( "ADD SRC FIL: " . getEngineSrcDir() . $file . "\n" );

	addSrcFile( getEngineSrcDir() . $file );
}

function addLibSrcDir( $dir )
{
	addSrcDir( T3DGenerator::getLibSrcDir() . $dir );
}

function addLibSrcFile( $file )
{
	addSrcDir( T3DGenerator::getLibSrcDir() . $file );
}

function addLibIncludePath( $path )
{
    // We need to make the include paths relative to the project file location!
	addIncludePath( getAppLibSrcDir() . $path ); 
}

function getAppLibSrcDir()
{
    // We need to make the include paths relative to the project file location!
    return "../" . getLibSrcDir();
}

function addAppIncludePath( $path )
{
	// We need to make the include paths relative to the project file location!
	addIncludePath( getAppEngineSrcDir() . $path ); 
}

function getAppEngineSrcDir()
{
    // We need to make the include paths relative to the project file location!
    return "../" . getEngineSrcDir();
}

function getAppEngineBinDir()
{
    // We need to make the include paths relative to the project file location!
    return "../" . getEngineBinDir();
}

function getEngineSrcDir()
{
	return T3DGenerator::getEngineSrcDir();
}

function getLibSrcDir()
{
	return T3DGenerator::getLibSrcDir();
}

function getEngineBinDir()
{
	return T3DGenerator::getEngineBinDir();
}

function addIncludePath( $path )
{
	//echo( "ADD INCLUDE: " . $path . "\n" );    

	T3DGenerator::addIncludePath( $path );
}
/// Add a preprocessor directive/define
function addProjectDefine( $d, $v = null )
{	
	T3DGenerator::addProjectDefine( $d, $v );
}
/// Add a list of defines in one call
function addProjectDefines()
{
	$args  = func_get_args();
	$count = func_num_args();
	
	if( $count > 0 )
		T3DGenerator::addProjectDefines( $args );
	else
		echo( "addProjectDefines() - no arguments passed!" );
}

function setProjectGUID( $guid )
{
	T3DGenerator::setProjectGUID( $guid );
}

function setProjectModuleDefinitionFile( $mdef )
{
	T3DGenerator::setProjectModuleDefinitionFile( $mdef );
}


function addProjectLibDir( $dir )
{
    T3DGenerator::addProjectLibDir( $dir );
}

function addProjectLibInput( $lib_name, $libDebug = null )
{
    T3DGenerator::addProjectLibInput( $lib_name, $libDebug );
}

function addProjectIgnoreDefaultLib( $lib )
{
	T3DGenerator::addProjectIgnoreDefaultLib( $lib );
}

function copyFileToProject( $sourcePath, $projPath )
{
    T3DGenerator::copyFileToProject( $sourcePath, $projPath );
}

function addProjectDependency( $pd )
{
    T3DGenerator::addProjectDependency( $pd );
}

function removeProjectDependency( $pd )
{
    T3DGenerator::removeProjectDependency( $pd );
}

function addProjectReference( $refName, $version = "" )
{
    T3DGenerator::addProjectReference( $refName, $version );
}

// disable a specific project compiler warning
function disableProjectWarning( $warning )
{	
	T3DGenerator::disableProjectWarning( $warning );
}


function setGameProjectName($name)
{
   T3DGenerator::setGameProjectName($name);
}

function getGameProjectName()
{
   return T3DGenerator::getGameProjectName();
}

function setToolBuild($tb)
{
   T3DGenerator::setToolBuild($tb);
}

function getToolBuild()
{
   return T3DGenerator::getToolBuild();
}

function setWatermarkBuild($wb)
{
   T3DGenerator::setWatermarkBuild($wb);
}

function getWatermarkBuild()
{
   return T3DGenerator::getWatermarkBuild();
}

function setPurchaseScreenBuild($psb)
{
   T3DGenerator::setPurchaseScreenBuild($psb);
}

function getPurchaseScreenBuild()
{
   return T3DGenerator::getPurchaseScreenBuild();
}

function setDemoBuild($db)
{
   T3DGenerator::setDemoBuild($db);
}

function getDemoBuild()
{
   return T3DGenerator::getDemoBuild();
}

function setObjectLimitBuild($olb)
{
   T3DGenerator::setObjectLimitBuild($olb);
}

function getObjectLimitBuild()
{
   return T3DGenerator::getObjectLimitBuild();
}

function setTimeOutBuild($tob)
{
   T3DGenerator::setTimeOutBuild($tob);
}

function getTimeOutBuild()
{
   return T3DGenerator::getTimeOutBuild();
}

function inProjectConfig()
{
   return T3DGenerator::inProjectConfig();
}

// On Windows, 1 - Console, 2 - Windows 
function setProjectSubSystem( $subSystem )
{
    T3DGenerator::setProjectSubSystem( $subSystem );
}

// Sets whether to use /MT or /MD code generation/runtime on Windows
// /MD plays better with multiple dynamic libraries in a project (and with certain libraries (like Qt)
// /MD also generates smaller binaries as the runtime isn't included in each module, memory is handled consistently, etc
// You must include or install via the redistributable package the appropriate VS runtime for end users.  
function setDLLRuntime ($val)
{
    T3DGenerator::setDLLRuntime( $val );
}

//-------------------------------------------------------------------------------- UTIL

// Some versions of PHP4 are unable to recusively create directories.
// The version of PHP that is distributed with Mac OS 10.4 suffers from this.
function mkdir_r($path, $mode)
{
   if( @mkdir( $path, $mode ) or file_exists( $path ) ) 
   	return true;
   	
   return ( mkdir_r( dirname( $path ), $mode ) and mkdir( $path, $mode ) );
}

// This is used inside an if statement in the smarty templates
function dontCompile( $string, $output )
{
   // Skip marking header files to be excluded from the 
   // build.  It confuses VS2010 and it will not put the 
   // file into the correct filter folder.
   //
   if ( preg_match( '#^.*\.(h|hpp|hh|inc)$#i', $string ) )
      return false;

   if( !is_array( $output->dont_compile_patterns ) )
        return false;
   
   foreach( $output->dont_compile_patterns as $pattern )   
      if( preg_match( $pattern, $string ) )
         return true;
      
   return false;
}


/// Generates and returns a randomly generated uuid in the form:
///
/// {xxxxxxxx-xxxx-4xxx-Yxxx-xxxxxxxxxxxx}
///
/// Where Y is either 8, 9, A, or B.  This is known as 
/// a v4 UUID.  See...
///
/// http://en.wikipedia.org/wiki/Universally_Unique_Identifier#Version_4_.28random.29
///
function gen_uuid()
{
    return sprintf( '{%04x%04x-%04x-%04x-%04x-%04x%04x%04x}', 
        // 32 bits for "time_low" 
        mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), 
 
        // 16 bits for "time_mid" 
        mt_rand( 0, 0xffff ), 
 
        // 16 bits for "time_hi_and_version", 
        // four most significant bits holds version number 4 
        mt_rand( 0, 0x0fff ) | 0x4000, 
 
        // 16 bits, 8 bits for "clk_seq_hi_res", 
        // 8 bits for "clk_seq_low", 
        // two most significant bits holds zero and one for variant DCE1.1 
        mt_rand( 0, 0x3fff ) | 0x8000, 
 
        // 48 bits for "node" 
        mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ) 
    ); 
}

?>
