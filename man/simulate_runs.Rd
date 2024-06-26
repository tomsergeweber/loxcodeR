% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/simulation.R
\name{simulate_runs}
\alias{simulate_runs}
\alias{simulate_runs,lox_casette-method}
\title{Simulate n lox recombination events}
\usage{
simulate_runs(lox, n)

\S4method{simulate_runs}{lox_casette}(lox, n)
}
\arguments{
\item{lox}{vector of lox sites}

\item{n}{number of recombination events to run}
}
\value{
vector of lox sites after n recombinations
}
\description{
Simulate n lox recombination events
}
\examples{
# Load required packages
library(loxcodeR)

# Example usage
# Assuming lox is defined and has the required structure
# simulate_runs(lox = c("lox1", "lox2"), n = 10)
}
