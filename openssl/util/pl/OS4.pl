#!/usr/local/bin/perl
#
# OS4.pl - Amiga OS4
#

$o='/';
$cp='cp';
$rm='-rm -f';
$mkdir='mkdir';

# C compiler stuff
$cc="ppc-amigaos-gcc";
$cfile="-c ";
$cflags="";
$app_cflag="\$(ADD) -DAMISSL -D__USE_INLINE__ -DB_ENDIAN -DTHIRTY_TWO_BITS -DOPENSSL_NO_FP_API -DOPENSSL_NO_ENGINE -I\$(AmiSSL)/include -I\$(AmiSSL)/openssl -g -O2";
$lib_cflag="\$(ADD) -nostdinc -mbaserel -mcheck68kdest -DAMISSL -DAMISSL_COMPILE -D__USE_INLINE__ -DB_ENDIAN -DTHIRTY_TWO_BITS -DOPENSSL_NO_FP_API -DOPENSSL_NO_ENGINE -I\$(AmiSSL)/include -I\$(AmiSSL)/libcmt/include -g -O2";
$obj='.o';
$ofile='-o ';
$define='-D';
$include='-I';

# EXE linking stuff
$link='${CC}';
$lflags='-lauto -lamisslauto';
$efile='-o ';
$exep='';
$ex_libs="";

# static library stuff
$mklib='ar r';
$mlflags='';
$ranlib='ranlib';
$plib='lib';
$libp=".a";
$shlibp=".a";
$lfile='';

$asm='as';
$afile='-o ';
$bn_mulw_obj="";
$bn_mulw_src="";
$des_enc_obj="";
$des_enc_src="";
$bf_enc_obj="";
$bf_enc_src="";

$src_dir=~ s/\.$//;
$maxchars=2048;

sub do_lib_rule
	{
	local($obj,$target,$name,$shlib)=@_;
	local($ret,$_,$Name);
	
	$target =~ s/\//$o/g if $o ne '/';
	($Name=$name) =~ tr/a-z/A-Z/;

	$ret.="$target: \$(${Name}OBJ)\n";
	$ret.="\t-\$(RM) $target\n";
	$ret.="\t\$(MKLIB) $target \$(${Name}OBJ)\n";
	$ret.="\t\$(RANLIB) $target\n\n";
	}

sub do_link_rule
	{
	local($target,$files,$dep_libs,$libs,$sha1file,$openssl)=@_;
	local($ret,$_);
	
	$file =~ s/\//$o/g if $o ne '/';
	$n=&bname($target);
	$ret.="$target: $files $dep_libs\n";
	$ret.="\t\$(LINK) ${efile}$target $files \$(LFLAGS) \n\n";
	return($ret);
	}

1;
