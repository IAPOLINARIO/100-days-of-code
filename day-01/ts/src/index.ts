import {Command} from '@oclif/command'

class AgeToDays extends Command {
  static description = 'Converts specified year to days'
  static args = [{name: 'years'}]
  static daysInYear = 365

  async run() {
    const {args} = this.parse(AgeToDays)
    const years: number = args.years
    if (years === null || isNaN(years)) {
      this.log('a valid year is needed')
      return
    }

    this.log(this.calculateDaysFromYear(years).toString())
  }

  calculateDaysFromYear(year: number) {
    return year * AgeToDays.daysInYear
  }
}

export = AgeToDays
