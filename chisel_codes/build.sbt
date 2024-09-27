/*scalaVersion := "2.13.10"
scalacOptions += "-language:higherKinds"
//addCompilerPlugin("org.typelevel" %% "kind-projector" % "0.10.3" cross CrossVersion.binary)
addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % "3.6.0" cross CrossVersion.full)
libraryDependencies ++= Seq(
  "edu.berkeley.cs" %% "chisel3" % "3.6.0",
  "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % "test",
  "edu.berkeley.cs" %% "chisel-iotesters" % "2.5.1" % "test"
  // https://mvnrepository.com/artifact/org.chipsalliance/chisel-plugin
libraryDependencies += "org.chipsalliance" %% "chisel-plugin" % "6.0.0"

)
turbo := true
//useSuperShell := false
scalacOptions ++= Seq(
  "-deprecation",
  "-encoding", "UTF-8",
  "-feature",
  "-unchecked",
  "-Xsource:2.13.10",
  "-language:reflectiveCalls"
)*/
// build.sbt
scalaVersion := "2.13.12"
val chiselVersion = "6.0.0"
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full)
libraryDependencies += "org.chipsalliance" %% "chisel" % chiselVersion
// https://mvnrepository.com/artifact/edu.berkeley.cs/chiseltest
libraryDependencies += "edu.berkeley.cs" %% "chiseltest" % "6.0.0"
// https://mvnrepository.com/artifact/org.scalatest/scalatest
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.18" % Test


turbo := true
scalacOptions ++= Seq(
  "-deprecation",
  "-encoding", "UTF-8",
  "-feature",
  "-unchecked",
  "-Xsource:2.13.12",
  "-language:reflectiveCalls"
)


/*lazy val root = (project in file(".")).settings(
  name := "my-project",
  version := "1.0",
  mainClass := "Main"
) */